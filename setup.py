from distutils.core import setup, Extension
import numpy

setup(
    name='murmur2py3',
    version='0.0.1',
    ext_modules=[
        Extension(
            "murmur2py3",
            [
                "src/murmur2py3.cc",
                "src/MurmurHash2.cpp",
            ],
            include_dirs=[
                numpy.get_include(),
                'include/'
            ],

        )
    ],
    url="https://github.com/alphajin1/murmur2py3",
    author="Jinil Nam",
    author_email="alphajin1@gmail.com",
    description="murmur2_64a python3 wrapper"
)
