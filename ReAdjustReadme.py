with open('README.md') as f:
    lines = f.readlines()
print(lines)
outputFile = ""
for i in range(len(lines)):
    outputFile = "<br/>"+outputFile + lines[i]
print(outputFile)  
newFile = open("README.md","w")
newFile.write(outputFile)
