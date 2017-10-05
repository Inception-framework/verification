from LoadGenerator import LoadGenerator
from StoreGenerator import StoreGenerator
from AddGenerator import AddGenerator
from SubGenerator import SubGenerator
from MulGenerator import MulGenerator
from DivGenerator import DivGenerator
from ShiftGenerator import ShiftGenerator

class GeneratorFactort():

	    def resolve(type):
	        if type == "Load": 
	            return LoadGenerator()
	        if type == "Store": 
	            return StoreGenerator()
	        if type == "Add": 
	            return AddGenerator()
	        if type == "Sub": 
	            return SubGenerator()
	        if type == "Mul": 
	            return MulGenerator()
	        if type == "Div": 
	            return DivGenerator()
	        if type == "Shift": 
	            return ShiftGenerator()
