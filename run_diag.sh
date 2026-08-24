#!/bin/bash

# Путь к бинарнику
ELF_FILE="diag_sram.elf"
GDB_INIT="gdb_commands.init"

# Проверяем, скомпилирован ли проект
if [ ! -f "$ELF_FILE" ]; then
    echo "Ошибка: Файл $ELF_FILE не найден! Сначала выполните команду 'make'."
    exit 1
fi

# Обработка аргументов командной строки
INTERACTIVE_MODE=0
if [ "$1" == "-i" ] || [ "$1" == "--interactive" ]; then
    INTERACTIVE_MODE=1
fi

# Если выбран интерактивный режим, создаем временный init-файл без таймера
if [ $INTERACTIVE_MODE -eq 1 ]; then
    echo "=== Настройка GDB для ИНТЕРАКТИВНОГО РЕЖИМА ==="
    # Копируем всё, кроме блока с continue & и sleep 15
    sed '/# Фоновый запуск/,+5d' $GDB_INIT > .gdb_interactive.init
    # Добавляем обычный continue на конце
    echo "continue" >> .gdb_interactive.init
    CURRENT_INIT=".gdb_interactive.init"
else
    echo "=== Настройка GDB для АВТОМАТИЧЕСКОГО ТЕСТА (15 сек) ==="
    CURRENT_INIT=$GDB_INIT
fi

echo "=== Запуск OpenOCD в фоновом режиме ==="
# Запускаем OpenOCD. Если вывод мешает, раскомментируйте перенаправление в лог.
openocd -f interface/stlink.cfg -f target/stm32l4x.cfg > openocd.log 2>&1 &
OPENOCD_PID=$!

# Даем OpenOCD время, чтобы инициализировать ST-Link и открыть порт 3333
sleep 1

# Проверяем, запустился ли OpenOCD успешно
if ! kill -0 $OPENOCD_PID 2>/dev/null; then
    echo "Ошибка: Не удалось запустить OpenOCD! Проверьте подключение ST-Link."
    exit 1
fi

echo "=== Подключение GDB и загрузка софта в SRAM ==="
# Запускаем GDB с выбранным сценарием
gdb-multiarch -x $CURRENT_INIT $ELF_FILE

echo "=== Сессия завершена. Завершение работы OpenOCD ==="
# Завершаем фоновый процесс OpenOCD
kill $OPENOCD_PID
wait $OPENOCD_PID 2>/dev/null

# Удаляем временный файл конфигурации, если он был создан
if [ -f ".gdb_interactive.init" ]; then
    rm ".gdb_interactive.init"
fi

echo "=== Скрипт успешно завершил работу ==="

