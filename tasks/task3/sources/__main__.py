import sys
import datetime
from Aphorism import *
from Proverb import *
from Riddle import *
from WisdomGenerator import *
from WisdomSorter import *

if __name__ == "__main__":
    parameters = sys.argv;
    start = datetime.datetime.now()
    container = []
    if parameters[1] == "-r":
        n = int(parameters[2])
        for i in range(n):
            container.append(WisdomGenerator.GenerateWisdom())
    else:
        inputFile = open(parameters[2], "rb")
        while True:
            wisdomType = inputFile.readline()
            if(not wisdomType):
                break
            wisdomType = wisdomType.decode("utf-8").rstrip('\n')
            title = str(inputFile.readline().decode("utf-8").rstrip('\n'))
            content = inputFile.readline().decode("utf-8").rstrip('\n')
            if wisdomType == "0":
                container.append(Aphorism(title, content))
            elif wisdomType == "1":
                container.append(Proverb(title, content))
            else:
                container.append(Riddle(title, content))
        inputFile.close()
    output1 = open(parameters[3], "w")
    output1.write(str(len(container)) + '\n')
    for i in container:
        output1.write(i.typename + '\n')
        output1.write(i.title + '\n')
        output1.write(i.text + '\n')
        output1.write(str(i.characteristic) + '\n')
    output1.close()
    WisdomSorter.StraightSort(container)
    output2 = open(parameters[4], "w")
    output2.write(str(len(container)) + '\n')
    for i in container:
        output2.write(i.typename + '\n')
        output2.write(i.title + '\n')
        output2.write(i.text + '\n')
        output2.write(str(i.characteristic) + '\n')
    output2.close()
    finish = datetime.datetime.now()
    print((finish - start).microseconds)


