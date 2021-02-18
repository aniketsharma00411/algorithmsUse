import unittest
from Python.duplicate_zeros import duplicate_zeros


class Test(unittest.TestCase):

    def test_1(self):
        result = duplicate_zeros([0, 1])
        self.assertEqual([0, 0], result)

    def test_2(self):
        result = duplicate_zeros([0, 1, 0])
        self.assertEqual([0, 0, 1], result)

    def test_3(self):
        result = duplicate_zeros([1, 0, 2, 3, 0, 4, 5, 0])
        self.assertEqual([1, 0, 0, 2, 3, 0, 0, 4], result)

    def test_4(self):
        result = duplicate_zeros([0, 0, 0, 0, 1])
        self.assertEqual([0, 0, 0, 0, 0], result)

    def test_5(self):
        result = duplicate_zeros([1, 0, 2, 3, 0, 4, 5, 0])
        self.assertEqual([1, 0, 0, 2, 3, 0, 0, 4], result)
