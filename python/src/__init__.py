"""
    clenshawcurtisexperiment --- An OpenTURNS module
    ==================================

    Contents
    --------
      'clenshawcurtisexperiment' is a module for OpenTURNS

"""

import sys
if sys.platform.startswith('win'):
    # this ensures OT dll is loaded
    import openturns

from .clenshawcurtisexperiment import *

__version__ = '0.0'

