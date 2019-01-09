#!/usr/bin/env python

"""Convert ENU data to latitude/longitude GPSVisualizer data"""

from __future__ import print_function
from __future__ import division

from Tkinter import Tk
from tkFileDialog import askopenfilename

import geodesy_converter_tester as gct

# TODO: Input ENU data is mandatory
# TODO: Output file names, freq are optional

def main():
    Tk().withdraw()
    filename = askopenfilename()
    print(filename)

if __name__ == '__main__':
    main()

