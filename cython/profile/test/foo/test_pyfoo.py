import unittest

import demo

class TestFoo(unittest.TestCase):

    def test_baz(self):
        a = 4
        b = 5
        ten = False
        self.assertEqual(demo.pyfoo.baz(a,b,ten), 22)

if __name__ == '__main__':
    unittest.main()
