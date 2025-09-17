from typing import NewType

FooType = NewType('FooType', int)

def foo(x: FooType, /) -> FooType: ...
