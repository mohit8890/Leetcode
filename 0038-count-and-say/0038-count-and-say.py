class Solution:
    def countAndSay(self, n: int) -> str:
        self.string = deque(["1"])
        for i in range(2, n+ 1):
            count, tmp = 0, 0
			# in the start len(self.string) is the length of previous string lengh
			# so we can make sure that we shouldn't pop the element which append in this time
            for i in range(len(self.string)):
                t = self.string.popleft()
                if not tmp: tmp, count = t, 1
                elif tmp != t:
                    self.string.extend([str(count), tmp])
                    count, tmp = 1, t
                else:
                    count += 1
            self.string.extend([str(count), tmp])
        return "".join(self.string)