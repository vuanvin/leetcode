from random import random


class RandomizedCollection(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.li = []
        self.di = {}

    def insert(self, val):
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        :type val: int
        :rtype: bool
        """
        self.li.append(val)
        if self.di.get(val):
            self.di[val].add(len(self.li) - 1)
            return False
        else:
            self.di[val] = {len(self.li) - 1}
            return True

    def remove(self, val):
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        :type val: int
        :rtype: bool
        """
        nli = len(self.li)
        rm_set = self.di.get(val)

        if rm_set:
            last_val = self.li[-1]
            if last_val == val:
                rm_set.remove(nli-1)
            else:
                rm_id = rm_set.pop()
                self.li[rm_id] = last_val
                last_set = self.di.get(last_val)
                last_set.remove(nli-1)
                last_set.add(rm_id)

            self.li.pop()
            return True

        return False

    def getRandom(self):
        """
        Get a random element from the collection.
        :rtype: int
        """
        return random.choice(self.li)

# Your RandomizedCollection object will be instantiated and called as such:
# obj = RandomizedCollection()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()