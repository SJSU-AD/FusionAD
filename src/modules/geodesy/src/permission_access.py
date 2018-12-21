#!/usr/bin/env python

"""Exceptions to be thrown when client attempts to access unaccesible permissions"""

class ReadOnlyError(Exception):
    pass

class UndeletablePropertyError(Exception):
    pass
