project('mypy-newtype', 'c')

py_mod = import('python')
py3 = py_mod.find_installation(pure: false)


py3.install_sources(
  'src/newtype/py.typed',
  'src/newtype/__init__.py',
  'src/newtype/__init__.pyi',
  'src/newtype/newtype.pyi',
  subdir: 'newtype')

py3.extension_module(
  'newtype',
  sources: ['src/newtype/newtype.c'],
  install: true,
  subdir: 'newtype')
