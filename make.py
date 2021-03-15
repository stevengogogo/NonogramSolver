import os

c_files = []
h_files = []

# Get filenames recursively
for root, dirs, files in os.walk("src", topdown=False):
   for name in files:
      
        fn = os.path.join(root, name)
        if fn.find(".h"):
            h_files.append(fn)
        elif fn.find(".c") and :
            h_files.append(fn)
        


print(filenames)