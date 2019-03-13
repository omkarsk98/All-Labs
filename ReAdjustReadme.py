with open('README.md') as f:
    lines = f.readlines()
outputFile = ""
for i in range(len(lines)):
    outputFile = outputFile + lines[i] + "  "
newFile = open("README.md","w")
newFile.write(outputFile)
