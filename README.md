#Murmur2
This is Murmur2 hash wrapper for Python.

##How to install
If you want to install Murmur2, execute the following script.
```bash
python setup.py install
```

##How to use
###import
Before you use murmur2, all you have to do is to import murmur2.
```
import murmur2
```

###use
I have inplamented one function, murmur64_a. The following script is a simple example of using murmu64_a

```
murmur2.murmur64_a("test",4,100)
```

First argument, "test", is input.
Second argument, 4, is the length of first argument.
Third argument is a seed. If you set a different seed, murmur64_a returns different hash value.

