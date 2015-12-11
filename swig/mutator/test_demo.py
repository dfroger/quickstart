import unittest
import demo

class TestFoo(unittest.TestCase):

    def test_int(self):

        foo = demo.Foo(42)
        self.assertEqual(foo.si, 42)

        foo.si = 17
        self.assertEqual(foo.si, 17)

        self.assertEqual(foo.gi, 34)

        with self.assertRaises(AttributeError):
            foo.gi = 10

    def test_class(self):
        foo = demo.Foo(42)
        self.assertFalse(foo.sbar.sb)

        foo.sbar = demo.Bar(True)
        self.assertTrue(foo.sbar.sb)

        self.assertFalse(foo.gbar.sb)

        with self.assertRaises(AttributeError):
            foo.gbar = demo.Bar(True)


if __name__ == '__main__':
    unittest.main()
