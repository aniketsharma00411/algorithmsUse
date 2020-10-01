import unittest
from Python.next_president import winner

class TestStringMethods(unittest.TestCase):
    
    def test_1(self):
        president = winner([1])
        self.assertEqual(1, president)

    def test_2(self):
        president = winner([1,1])
        self.assertEqual(1, president)

    def test_3(self):
        president = winner([1,2,1])
        self.assertEqual(1, president)

    def test_4(self):
        president = winner([16,16,16,16,16,16,11,26,5,3])
        self.assertEqual(16, president)

    def test_5(self):
        president = winner([1,2,3,1,1,2,5,1,1])
        self.assertEqual(1, president)