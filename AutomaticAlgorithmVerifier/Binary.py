class Binary():

	#def __init__(self):

    @classmethod
    def load(self, fileName):
    	with open(fileName, mode='rb') as file:
    		fileContent = file.read()
    	return fileContent