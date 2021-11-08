class Riddle:
    def __init__(self, title, text):
        self.title = title
        self.text = text
        counter = 0.0
        for i in range(len(text)):
            if (not (text[i] >= 'a' and text[i] <= 'z' or text[i] >= 'A' and text[i] <= 'Z' or text[i] == ' ')):
                counter += 1
        self.characteristic = counter / len(text)
        self.typename = "Riddle"
