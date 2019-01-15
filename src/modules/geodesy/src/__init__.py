import os

files = os.listdir(os.path.join(os.path.abspath(""), ""))
__all__ = [fileName for fileName in files if fileName[:2] != "__"]
