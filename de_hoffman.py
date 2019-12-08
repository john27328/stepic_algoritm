#nChar, lenH = (int(i) for i in input().split())
#
#codeList = []
#for i in range(nChar):
#    s, code = input().split(':')
#    codeList.append([s, code])
#    
#codeStr = input()

#nChar = 1
#lenH = 1
#codeList = [['a', '0'],]
#codeStr = ["0",]

nChar = 4
lenH = 14
class Char(object):
    def __init__(self, ch, code):
        self.ch = ch
        self.code = code

codeList = [Char('a', '0'),
            Char('b', '10'),
            Char('c', '110'),
            Char('d', '111')]
codeStr = "01001100100111"

if (nChar == 1):
    print(codeList[0].ch* lenH)
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
                    carrent = self.r
                if(ch.code[0]  == "1"):
                    carrent = self.l
                if (carrent == None):
                    carrent = Hoffman()
                ch.code = ch.code[1:]
                carrent.add(ch)

    tr = Hoffman()
    for i in codeList:
        tr.add(i)
        
                

    print("end")
    