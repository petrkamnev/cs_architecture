import random
from Aphorism import *
from Proverb import *
from Riddle import *

kAlphabet = "abcdefghijklmnopqrstuvwxyz!#$%^&*()_-+=.,/?"
class WisdomGenerator:
    def GenerateWisdom():
        title = ""
        content = ""
        titleLength = random.randint(1,10)
        contentLength = random.randint(1,100)
        for i in range(titleLength):
            title += kAlphabet[random.randint(0, 42)]
        for i in range(contentLength):
            content += kAlphabet[random.randint(0, 42)]
        wisdomType = random.randint(1,3)
        if wisdomType == 1:
            return Aphorism(title, content)
        elif wisdomType == 2:
            return Proverb(title, content)
        else:
            return Riddle(title, content)
