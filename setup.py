from distutils.core import setup, Extension
import numpy.distutils.misc_util

setup(
    name = 'murmur2',
    version = '1.0.1',
    ext_modules=[
        Extension(
            "murmur2", 
            [
                "src/murmur2.cc",
                "src/MurmurHash2.cpp",
            ],
            include_dirs=[
                numpy.distutils.misc_util.get_numpy_include_dirs()[0],
                'include/'
            ],
            
        )
    ],
    url = "https://github.com/orion46/murmur2",
    author = "Nobutaka Ito",
    author_email = "earth.nobu.light@gmail.com",
    description  = "murmur2_64a python wrapper"
)

