class Jar:
    def __init__(self, capacity=12):
        self._capacity = 0
        if capacity >= 0 and capacity < 13:
            self._capacity = capacity
        else:
            raise ValueError
        self._size = 0

    def __str__(self):
        str = self.size * '🍪'
        return str

    def deposit(self, n):
        if self._size + n <= self._capacity:
            self._size = self._size + n
            return self._size
        else:
            raise ValueError

    def withdraw(self, n):
        if self._size - n >= 0:
            self._size = self.size - n
            return self._size
        else:
            raise ValueError

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size

def main():
    jar = Jar()
    print(jar.capacity)
    print(jar.size)
    #Now let's build a pyramid :D
    for cookie in range(jar.capacity):
        jar.deposit(1)
        print(jar)
    #raise ValueError:
    # jar.deposit(2)
    # print(jar)
    for cookie in range(jar.capacity):
        jar.withdraw(1)
        print(jar)
    #raise ValueError:
    # jar.withdraw(2)
    # print(jar)

main()

# Sławek