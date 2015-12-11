import unittest
import demo

class TestFoo(unittest.TestCase):

    def test_int_setter(self):
        foo = demo.Foo(42)
        self.assertEqual(foo.si, 42)

        foo.si = 17
        self.assertEqual(foo.si, 17)

    def test_int_getter(self):
        foo = demo.Foo(42)
        self.assertEqual(foo.gi, 84)

        with self.assertRaises(AttributeError):
            foo.gi = 10

    def test_class_setter(self):
        foo = demo.Foo(42)
        self.assertFalse(foo.sbar.sb)

        foo.sbar = demo.Bar(True)
        self.assertTrue(foo.sbar.sb)

    def test_class_getter(self):
        foo = demo.Foo(42)
        self.assertFalse(foo.gbar.sb)

        with self.assertRaises(AttributeError):
            foo.gbar = demo.Bar(True)

    def test_class_getter_modifs(self):
        foo = demo.Foo(42)
        bar = foo.gbar
        bar.sb = True
        self.assertTrue(foo.gbar.sb)

    def test_vector_getter(self):
        foo = demo.Foo(42)
        v = foo.gv
        self.assertEqual(len(v), 3)
        self.assertEqual(v[0], 1)
        self.assertEqual(v[1], 2)
        self.assertEqual(v[2], 3)

    def test_vector_getter_modif(self):
        foo = demo.Foo(42)
        v = foo.gv
        v[1] = 33
        self.assertEqual(len(foo.gv), 3)
        self.assertEqual(foo.gv[0], 1)
        self.assertEqual(foo.gv[1], 33)
        self.assertEqual(foo.gv[2], 3)


if __name__ == '__main__':
    unittest.main()
