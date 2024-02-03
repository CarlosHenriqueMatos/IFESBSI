# this code was made from https://www.youtube.com/watch?v=ei9-eCyon7I&ab_channel=Programa%C3%A7%C3%A3oDin%C3%A2mica
# adapted by Programação Dinamica youtube channel
# atributos
#1 . numerador ; 2 denominador

#metodos
#somar; subtrair; multiplicar; dividir; inverter;

class Frac:
    def __init__(self, num:float, den:float):

        self.num = num
        if den == 0:
            self.den = 1
        else:
            self.den = den

    def add(self, outra:float)-> float:
        if self.den == outra.den:
            num = self.num + outra.den
            den = self.den
            return Frac(num, den)
        num = self.num * outra.den + outra.den*self.den
        den = self.den+outra.den
        return Frac(num,den)
    
    def sub(self, outra:float)-> float:
        return self.add(outra.reverse())

    def multiply(self, outra:float) -> float:
        numerator = self.num * outra.num
        denominator = self.den * outra.den
        return Frac(numerator, denominator)
    
    def divide(self:float, outra:float) -> float:
        return self.multiply(outra.invert())

    def invert(self:float) -> float:
        return Frac(self.den, self.num)
    
    def reverse(self:float) -> float:
        return Frac(-self.num, self.den)
    
    def simplify(self):
        pass

    def __str__(self:float) -> str:
        representation = "{}/{}".format(self.num, self.den)
        return representation
    
    def __repr__(self:float) -> str:
        representation = "Fracao({}/{})".format(self.num,
                                                 self.den)
        return representation
    
    def __add__(self:float, outra:float):
        return self.add(outra)
    
    def __sub__(self:float, outra:float):
        return self.sub(outra)
    
    def __mul__(self:float, outra:float):
        return self.multiply(outra)
    
    def __neg__(self:float) -> float:
        return self.reverse()

class Person:
    def __init__(self,name:str, id:int) -> None:
        self.name = name
        self.id = id
        self.token_id = str(self.name) + str(self.id) + 'secret_key'

    def show_statement(self):
        print('Showing statment')
    
class Client(Person):
    def __init__(self, name:str, id:int, total_shopping:float) -> None:
        super().__init__(name, id)
        self.total_shopping = total_shopping
        self.token_client = str(self.token_id) + str(self.total_shopping)

    def show_statement(self) -> None:
        print("Showing client statment")    

if __name__ == '__main__':
    primeira = Frac(4, 5)
    print(primeira)
    print(primeira.num, primeira.den)
    x = Client("Carlos","123","53")
    print(x.name)
