
class PriorityQueue:
    def __init__(self):
        self._d = [0,]
    
    def insert(self, value):
        self._d.append(value)
        self._d[0] += 1
        currentIndex = self._d[0]
        perentIndex = self.perentIndex(currentIndex)
        while (self._d[currentIndex] > self._d[perentIndex] and currentIndex > 1):
            self._d[currentIndex], self._d[perentIndex] =  self._d[perentIndex], self._d[currentIndex]
            currentIndex = perentIndex
            perentIndex = self.perentIndex(currentIndex)

    def ExtractMax(self):
        returnValue = self._d[1]
        if (self._d[0] == 1):
            self._d.pop(self._d[0])
            self._d[0] -= 1
            return returnValue
        self._d[1] = self._d.pop(self._d[0])
        self._d[0] -= 1
        n = self._d[0]

        currentIndex = 1
        lChildIndex = self.lChildIndex(currentIndex)
        rChildIndex = self.rChildIndex(currentIndex)
        while(lChildIndex <= n and self._d[currentIndex] < self._d[lChildIndex] or
              rChildIndex <= n and self._d[currentIndex] < self._d[rChildIndex] ):
            if(rChildIndex > n or self._d[lChildIndex] > self._d[rChildIndex]):
                self._d[currentIndex], self._d[lChildIndex] = self._d[lChildIndex], self._d[currentIndex]
                currentIndex = lChildIndex
                lChildIndex = self.lChildIndex(currentIndex)
                rChildIndex = self.rChildIndex(currentIndex)
            else:
                self._d[currentIndex], self._d[rChildIndex] = self._d[rChildIndex], self._d[currentIndex]
                currentIndex = rChildIndex
                lChildIndex = self.lChildIndex(currentIndex)
                rChildIndex = self.rChildIndex(currentIndex)

        return returnValue


    def lChildIndex(self, index):
        return 2 * index

    def rChildIndex(self, index):
        return 2 * index + 1

    def perentIndex(self, index):
        return index // 2

if __name__ == "__main__":
    t = PriorityQueue()
    nCommand = int(input())
    for i in range(nCommand):
        commandLine = input().split()
        if (commandLine[0] == "Insert"):
            t.insert(int(commandLine[1]))
        if (commandLine[0] == "ExtractMax"):
            print(t.ExtractMax()) 
