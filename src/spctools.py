import os
from cffi import FFI
from numpy import float64, array, uint8

here = os.path.abspath(os.path.dirname(__file__))
header = os.path.join(here, 'spctools.h')

# TODO: compile and parse instead for this hack
lines = open(header).readlines()
functions = []
for line in lines:
    if not (line.startswith('#') or
            line.startswith('\n') or
            line.startswith('extern') or
            line.startswith('{') or
            line.startswith('}')):
        functions.append(line.replace('SPCTOOLS_API ', ''))

ffi = FFI()
ffi.cdef(''.join(functions))
lib = ffi.dlopen(os.path.join(here, 'spctools.dll'))


def plot(x, y):
    assert(len(x) == len(y))
    xa = array(x, dtype=float64)
    pxa = ffi.cast("double *", xa.ctypes.data)

    ya = array(y, dtype=float64)
    pya = ffi.cast("double *", ya.ctypes.data)

    lib.Plot(pxa, pya, len(xa))


def hold(on):
    if on:
        lib.Hold(1)
    lib.Hold(0)


def show():
    lib.Show()
