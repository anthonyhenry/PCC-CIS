def newSect():
    print("---")

# Object
    # An object is a bit of self-contained code(functions) and data(variables)

# Definitions
    # Class - a template
    # Method or Message - A defined capability of a class
    # Field or attribute - A bit of data in a class
    # Object or Instance - A particular instance of a class

class PartyAnimal: # How to declare a class. Convention is to capitalize first 
    x = 0 # Some data for our object

    def party(self):
        self.x = self.x + 1 # self.x gets the x variable from above
        print("So far", self.x)

animal = PartyAnimal() # Construct a PartyAnimal object to store in 'animal'
anotherAnimal = PartyAnimal()

animal.party() # Run the party function for the animal object
animal.party()
anotherAnimal.party()
animal.party()

newSect()

# You can use type() and dir() on your objects
print(type(animal))
print(dir(animal)) # For dir(), ignore the ones with '__'. Those are built in functions

newSect()

# Constructors and Destructors
    # Constructors and Destructors are built in functions that run when the object is created and destroyed
    # The constructor and destructor are optional. The constructor is typically used to set up variables. The destructor is seldom used.
class PartyAnimal2:
   x = 0

   def __init__(self):
     print('I am constructed')

   def party(self) :
     self.x = self.x + 1
     print('So far',self.x)

   def __del__(self):
     print('I am destructed', self.x)

an = PartyAnimal2()
an.party()
an.party()
an = 42
print('an contains',an)

newSect()

# Constructors can have additional parameters.  These can be used to set up instance variables for the particular instance of the class (i.e., for the particular object).
class PartyAnimal3:
   x = 0
   name = ""
   def __init__(self, z):
     self.name = z
     print(self.name,"constructed")

   def party(self) :
     self.x = self.x + 1
     print(self.name,"party count",self.x)

s = PartyAnimal3("Monkey")
j = PartyAnimal3("Giraffe")

s.party()
j.party()
s.party()

newSect()

# Inheritance
    # When we make a new class - we can reuse an existing class and inherit all the capabilities of an existing class and then add our own little bit to make our new class
    # The new class (child) has all the capabilities of the old class (parent) - and then some more
class FootballFan(PartyAnimal3):
   points = 0
   def touchdown(self):
      self.points = self.points + 7
      self.party()
      print(self.name,"points",self.points)

j = FootballFan("Jim")
j.party()
j.touchdown()