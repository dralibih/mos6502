# mos6502
Emulador del procesador Mos 6502 desarrollado en C

### Uso

Para simplificar el uso, copiar el siguiente alias.

`alias mos="make -s clean; make -s programa; echo ''; ./programa"`

Luego, ejecutar

`mos`

Caso contrario, ejecutar de la siguiente manera

`make clean`

`make programa`

`./programa`

### Programa de ejemplo
Para ilustrar el funcionamiento del emulador, se implementó un contador de
la forma

```
start:
	LDX #$0A  ; Cargar x con 0x0A
loop:
	DEX         ; X = X - 1
        BNE loop    ; if x != 0, ir a loop
	RTS   
```

