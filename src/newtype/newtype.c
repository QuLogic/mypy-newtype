#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject *
newtype_foo(PyObject *self, PyObject *obj)
{
    if (!PyLong_Check(obj)) {
        PyErr_SetString(PyExc_TypeError, "obj is incorrect type");
        return NULL;
    }
    return obj;
}

static int
newtype_mod_exec(PyObject *module)
{
    PyObject *int_obj = (PyObject *)&PyLong_Type;
    return PyModule_AddObjectRef(module, "FooType", int_obj);
}

static PyMethodDef newtype_methods[] = {
    {
        .ml_name = "foo",
        .ml_meth = &newtype_foo,
        .ml_flags = METH_O,
    },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef_Slot newtype_slots[] = {
    {Py_mod_exec, &newtype_mod_exec},
    { 0, NULL }
};

static struct PyModuleDef newtype_module = {
    .m_base = PyModuleDef_HEAD_INIT,
    .m_name = "newtype",
    .m_methods = newtype_methods,
    .m_slots = newtype_slots,
};

PyMODINIT_FUNC
PyInit_newtype(void)
{
    return PyModuleDef_Init(&newtype_module);
}
