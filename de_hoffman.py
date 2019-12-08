class Char(object):
    def __init__(self, ch, code):
        self.ch = ch
        self.code = code

nChar, lenH = (int(i) for i in input().split())

codeList = []
for i in range(nChar):
   s, code = input().split(': ')
   codeList.append(Char(s, code))
   
codeStr = input()

if (nChar == 1):
    print(codeList[0].ch * lenH)
else:
    class Hoffman(object):
        def __init__(self, l = None, r = None):
            self.l = l
            self.r = r
            self.d = None
        def add(self, ch):
            if (ch.code == ''):
                self.d = ch.ch
            else:
                if(ch.code[0]  == "0"):
                    if (self.r == None):
                        self.r = Hoffman()
                    ch.code = ch.code[1:]
                    self.r.add(ch)
                else:
                    if (self.l == None):
                        self.l = Hoffman()
                    ch.code = ch.code[1:]
                    self.l.add(ch)

    # построение дерева
    tr = Hoffman()
    for i in codeList:
        tr.add(i)
        
    str1 = ''            
    carrent = tr
    for i in codeStr:
        if (i == '0'):
            carrent = carrent.r
        else:
            carrent = carrent.l
        if (carrent.d != None):
            str1 += carrent.d
            carrent = tr


    print(str1)
    