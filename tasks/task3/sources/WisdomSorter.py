from Aphorism import *
from Proverb import *
from Riddle import *

class WisdomSorter:
    def StraightSort(container):
        for i in range(0, len(container)):
            index = i
            while index != 0 and container[index - 1].characteristic > container[index].characteristic:
                container[index - 1], container[index] = container[index], container[index - 1]
                index -= 1
