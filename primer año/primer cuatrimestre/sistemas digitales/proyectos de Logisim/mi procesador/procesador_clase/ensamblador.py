import sys

args = sys.argv


global contador_linea
contador_linea = 1

global exit
exit = sys.exit

def completarNumeroBits(s, numeroBits):
    while len(s) < numeroBits:
        s = "0" + s
    return s

def to_twos_complement(value, bit_width):
    if value >= 0:
        return value
    else:
        return (1 << bit_width) + value

def negative_value_ca2(value, bit_width):
    val = to_twos_complement(-value, bit_width)
    return val

def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]

def convertToPlainBase(n, b, nBits):
    res = numberToBase(n, b)
    s = ""
    for i in res:
        s += str(i)
    s = completarNumeroBits(s, nBits)
    return s

class Hexadecimal:
    def __init__ (self, valor: str, n_bits: int):
        if valor[0] == '0' and valor[1] == 'x':
            neo_valor = ""
            for i in range(2, len(valor), 1):
                neo_valor += valor[i]
            valor = neo_valor
        self.hexa = valor
        valor = int(self.hexa, 16)
        if valor >= (2**n_bits):
            raise ValueError(f"Error en la línea {contador_linea}: Valor hexadecimal fuera del rango de {n_bits} bits.")
    def get_valor_decimal(self):
        return int(self.hexa, 16)
    
    def get_valor_binario(self, n_bits):
        decimal = self.get_valor_decimal()
        return convertToPlainBase(decimal, 2, n_bits)

class Registro:
    def __init__(self, id_registro):
        self.id_registro = id_registro
    def get_valor (self):
        registros = ["000", "001", "010", "011", "100", "101", "110", "111"]
        nombres = ["R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7"]
        for i in range(len(nombres)):
            if self.id_registro == nombres[i]:
                return registros[i]
        return registros[0]

def AND_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: AND requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "000" + rb.get_valor()
def OR_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: OR requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "001" + rb.get_valor()
def XOR_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: XOR requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "010" + rb.get_valor()
def NOT_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: NOT requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "011" + "000"
def ADD_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: ADD requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "100" + rb.get_valor()
def SUB_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: SUB requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "101" + rb.get_valor()
def SHA_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: SHA requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "110" + rb.get_valor()
def SHL_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: SHL requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0000" + rd.get_valor() + ra.get_valor() + "111" + rb.get_valor()

def CMPLT_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: CMPLT requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0001" + rd.get_valor() + ra.get_valor() + "000" + rb.get_valor()
def CMPLE_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: CMPLE requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0001" + rd.get_valor() + ra.get_valor() + "001" + rb.get_valor()
def CMPEQ_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: CMPEQ requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0001" + rd.get_valor() + ra.get_valor() + "011" + rb.get_valor()
def CMPLTU_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: CMPLTU requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0001" + rd.get_valor() + ra.get_valor() + "100" + rb.get_valor()
def CMPLEU_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        rb = Registro(args[3])
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: CMPLEU requiere tres argumentos: Rd (registro de destino), Ra (registro del primer operando) y Rb (registro del segundo operando)")
        exit()
        return
    return "0001" + rd.get_valor() + ra.get_valor() + "101" + rb.get_valor()

def ADDI_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        val = Hexadecimal(args[3], 6)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: ADDI requiere tres argumentos: Rd (registro donde guardar el resultado), Ra (registro del primer operando) y 0xVAL (6 bits), valor del segundo operando.")
        exit()
        return
    return "0010" + rd.get_valor() + ra.get_valor() + val.get_valor_binario(6)

def LD_fn (args):
    try:
        rd = Registro(args[1])
        ra = Registro(args[2])
        val = Hexadecimal(args[3], 6)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: LD requiere tres argumentos: Rd (registro en el que se desea guardar la información) y otros dos argumentos Ra y 0xVAL (6 bits) tal que la dirección de memoria de la que se saca la información es la suma de Ra + 0xVAL")
        exit()
        return
    return "0011" + rd.get_valor() + ra.get_valor() + val.get_valor_binario(6)

def ST_fn (args):
    try:
        rb = Registro(args[1])
        ra = Registro(args[2])
        val = Hexadecimal(args[3], 6)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: ST requiere tres argumentos: Rb (registro que desea guardar en memoria) y otros dos argumentos Ra y 0xVAL (6 bits) tal que la dirección de memoria donde se guarda es la suma de Ra + 0xVAL")
        exit()
        return
    return "0100" + rb.get_valor() + ra.get_valor() + val.get_valor_binario(6)

def MOVI_fn (args):
    try:
        rd = Registro(args[1])
        val = Hexadecimal(args[2], 8)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: MOVI requiere dos argumentos: Rd (registro donde escribir la información) y 0xIMMED (valor hexadecimal de 8 bits que se quiere insertar directamente al registro)")
        exit()
        return
    return "0101" + rd.get_valor() + "0" + val.get_valor_binario(8)

def MOVHI_fn (args):
    try:
        rd = Registro(args[1])
        val = Hexadecimal(args[2], 8)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: MOVHI requiere dos argumentos: Rd (registro donde escribir la información) y 0xIMMED (valor hexadecimal de 8 bits que se quiere insertar directamente al registro)")
        exit()
        return
    return "0101" + rd.get_valor() + "1" + val.get_valor_binario(8)

def BZ_fn (args):
    try:
        rb = Registro(args[1])
        val = Hexadecimal(args[2], 8)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: BZ requiere dos argumentos: Rb (registro que se quiere verificar que es 0x0000) y 0xJUMP (valor hexadecimal de 8 bits del salto en Ca2 en caso de verificarse)")
        exit()
        return
    return "0110" + rb.get_valor() + "0" + val.get_valor_binario(8)
def BNZ_fn (args):
    try:
        rb = Registro(args[1])
        val = Hexadecimal(args[2], 8)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: BNZ requiere dos argumentos: Rb (registro que se quiere verificar que no es 0x0000) y 0xJUMP (valor hexadecimal de 8 bits del salto en Ca2 en caso de verificarse)")
        exit()
        return
    return "0110" + rb.get_valor() + "1" + val.get_valor_binario(8)

def IN_fn (args):
    try:
        rd = Registro(args[1])
        port = Hexadecimal(args[2], 8)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: IN requiere dos argumentos: Rd (registro donde escribir la información obtenida) y 0xPORT (valor hexadecimal de 8 bits del puerto de dónde obtener la información de entrada)")
        exit()
        return
    return "0111" + rd.get_valor() + "0" + port.get_valor_binario(8)

def OUT_fn (args):
    try:
        rd = Registro(args[1])
        port = Hexadecimal(args[2], 8)
    except Exception as e:
        print(e)
        print(f"Error en la línea {contador_linea}: IN requiere dos argumentos: Rd (registro donde escribir la información obtenida) y 0xPORT (valor hexadecimal de 8 bits del puerto de dónde obtener la información de entrada)")
        exit()
        return
    return "0111" + rd.get_valor() + "1" + port.get_valor_binario(8)

def RESTART_fn(args):
    val = negative_value_ca2(contador_linea-1, 8)
    my_hexa = ""
    n_val = numberToBase(val, 16)
    for i in n_val:
        my_hexa += hexa[i]
    return BZ_fn(["BZ", "R0", f"0x{my_hexa}"])

traductor = {
    "AND": AND_fn,
    "OR": OR_fn,
    "XOR": XOR_fn,
    "NOT": NOT_fn,
    "ADD": ADD_fn,
    "SUB": SUB_fn,
    "SHA": SHA_fn,
    "SHL": SHL_fn,
    "CMPLT": CMPLT_fn,
    "CMPLE": CMPLE_fn,
    "CMPEQ": CMPEQ_fn,
    "CMPLTU": CMPLTU_fn,
    "CMPLEU": CMPLEU_fn,
    "ADDI": ADD_fn,
    "LD": LD_fn,
    "ST": ST_fn,
    "MOVI": MOVI_fn,
    "MOVHI": MOVHI_fn,
    "BZ": BZ_fn,
    "BNZ": BNZ_fn,
    "IN": IN_fn,
    "OUT": OUT_fn,
    "RESTART": RESTART_fn,
}


class Nemonico:
    def __init__ (self, comando, params):
        self.comando = comando

if len(sys.argv) < 3:
    print("Arguments error: min 2 args (name of file and name of output)")
    exit()


def precompilado(archivo: str):


def compilado(codigo: str):


with open(sys.argv[1], 'r') as archivo:
    f = open(sys.argv[2], 'w')
    hexa = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A','B','C','D','E','F']
    lineas = archivo.readlines()
    for linea in lineas:
        sin_salto = linea.rstrip()
        token = sin_salto.split(" ")
        try:
            line_res = traductor[token[0]](token)
        except:
            print(f"Error fatal en la línea {contador_linea}: {token[0]} token no reconocido")
            exit()
        if len(sys.argv) == 3:
            f.write(line_res + "\n")
        elif sys.argv[3] == "hexa":
            decimal = int(line_res, 2)
            res = numberToBase (decimal, 16)
            result = ""
            for i in range(4-len(res)):
                f.write("0")
            for i in res:
                result += "" + hexa[i]
            f.write(result + "\n")
        contador_linea+=1