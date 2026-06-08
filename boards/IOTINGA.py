#!/bin/false

# This file is part of Espruino, a JavaScript interpreter for Microcontrollers
#
# Custom embedded Espruino target for IOTINGA.
#
# This target is intentionally based on boards/EMBED.py.
# It generates espruino_embedded.c/.h, but also includes the native
# Shadow JavaScript wrapper.
#
# Important:
#   - This board file must NOT depend on your real project Shadow implementation.
#   - libs/shadow/jswrap_shadow.c only declares/uses extern ShadowJs_* symbols.
#   - Your final application provides those ShadowJs_* symbols at link time.

import pinutils

info = {
    "name": "IOTINGA Embedded Espruino",
    # Same default as EMBED.py.
    # Tune this if you want a smaller/larger Espruino variable pool.
    "variables": 16000,
    # Keep the standard embedded output name so your existing copy step can stay
    # the same.
    "binary_name": "espruino_embedded.c",
    "build": {
        "libraries": [],
        "makefile": [
            # Standard EMBED.py flags
            "ESPR_EMBED=1",
            "USE_DEBUGGER=0",
            "DEFINES+=-DUSE_CALLFUNCTION_HACK",
            "DEFINES+=-DJSVAR_MALLOC",
            "DEFINES+=-DEMBED",
            # Shadow JS wrapper.
            #
            # This directory should contain:
            #   libs/shadow/jswrap_shadow.h
            #   libs/shadow/jswrap_shadow.c
            #
            # Do not put the real Shadow implementation here.
            "INCLUDE += -I$(ROOT)/libs/shadow",
            "WRAPPERSOURCES += libs/shadow/jswrap_shadow.c",
        ],
    },
}

chip = {
    "part": "EMBED",
    "family": "EMBED",
    "package": "",
    "ram": 0,
    "flash": 0,
    "speed": -1,
    "usart": 6,
    "spi": 3,
    "i2c": 3,
    "adc": 0,
    "dac": 0,
}

devices = {}


def get_pins():
    # EMBED.py fakes pins D0..D32 even though no hardware access is expected.
    return pinutils.generate_pins(0, 32)
