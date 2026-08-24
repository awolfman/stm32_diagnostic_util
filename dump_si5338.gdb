# Скрипт GDB для автоматического сохранения прошивок Si5338
set logging file si5338_0x70_dump.txt
set logging on
set $reg = 0
printf "--- START DUMP SI5338 AT 0x70 ---\n"
while ($reg < 255)
    set $val = i2c3_read_reg(0x70, $reg)
    printf "Reg 0x%02X: 0x%02X\n", $reg, $val
    set $reg = $reg + 1
end
set logging off

set logging file si5338_0x71_dump.txt
set logging on
set $reg = 0
printf "--- START DUMP SI5338 AT 0x71 ---\n"
while ($reg < 255)
    set $val = i2c3_read_reg(0x70, $reg)
    printf "Reg 0x%02X: 0x%02X\n", $reg, $val
    set $reg = $reg + 1
end
set logging off

printf "--- DUMP COMPLETE! FILES SAVED! ---\n"
