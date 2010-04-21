
import pyqtconfig

# These are installation specific values created when Hello was configured.
# The following line will be replaced when this template is used to create
# the final configuration module.
_pkg_config = {
    'stone_sip_dir':    'c:\\Python25\\sip',
    'stone_sip_flags':  '-x VendorID -t WS_WIN -x PyQt_OpenSSL -x PyQt_NoPrintRangeBug -t Qt_4_5_0 -x Py_v3 -g'
}

_default_macros = None

class Configuration(pyqtconfig.Configuration):
	"""The class that represents Hello configuration values.
	"""
	def __init__(self, sub_cfg=None):
		"""Initialise an instance of the class.

		sub_cfg is the list of sub-class configurations.  It should be None
		when called normally.
		"""
		# This is all standard code to be copied verbatim except for the
		# name of the module containing the super-class.
		if sub_cfg:
			cfg = sub_cfg
		else:
			cfg = []

		cfg.append(_pkg_config)

		pyqtconfig.Configuration.__init__(self, cfg)

class StoneModuleMakefile(pyqtconfig.QtModuleMakefile):
	"""The Makefile class for modules that %Import hello.
	"""
	def finalise(self):
		"""Finalise the macros.
		"""
		# Make sure our C++ library is linked.
		self.extra_libs.append("stone")

		# Let the super-class do what it needs to.
		pyqtconfig.QtModuleMakefile.finalise(self)
