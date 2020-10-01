"""
Given an array V of vote decisions, return the winner of the election.
You are guaranteed to have a winner. Also, you can assume the winner have more than
floor(n/2) votes in favor.
"""

from typing import List

def sortingTheArray(V: List[int]) -> int:  # pylint: disable=C0103
        """Solution with sorting array NLogN"""
        votes = V.copy()
        votes.sort()
        return votes[(len(votes) // 2)]

def winner(V: List[int]) -> int: # pylint: disable=C0103
        """Solution to problem."""
        return sortingTheArray(V)

if __name__ == "__main__":
    president = winner([48,25,48,49,4,44,48,37,48,22,48,48,48,2,48,48,32,48,6,48])
    print(president)
