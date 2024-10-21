class Solution:
    def decodeString(self, s: str) -> str:
        return self.decodeString1(s,0)

    def decodeString1(self, s, index):
        dstring = "" # correction here
        num = 0        
        while(index < len(s)):
            char = s[index]
            if char.isdigit():
                num = num*10 + int(char) # because int can be [1,300]
            elif char=='[':
                index+=1
                index, partstr = self.decodeString1(s,index)
                for i in range(num):
                    dstring+=partstr
                num=0
            elif char==']':
                return index,dstring
            else:
                dstring += char
            index+=1
        return dstring

        


        