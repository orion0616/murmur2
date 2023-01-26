# Murmur2py3
- This is Murmur2 hash wrapper for Python.
- This was forked and extended from https://www.github.com/orion46/murmur2

## How to install
If you want to install Murmur2, execute the following script.
```bash
python setup.py install
```
### Requirements
- Python >= 3.8
- numpy >= 1.22

## How to use
### import
Before you use murmur2py3, all you have to do is to import murmur2py3.
```
import murmur2py3
```

### use
I have inplamented one function, murmur64_a. The following script is a simple example of using murmu64_a

```python
murmur2py3.murmur64a("test", 4, 100)
```

First argument, "test", is input. <br>
Second argument, 4, is the length of first argument. <br>
Third argument is a seed. If you set a different seed, murmur64_a returns different hash value. <br>

