import subprocess
import os
import sys

BOARDS = [
    'keychron/k4/rgb/v1',
    'keychron/k4/rgb/v1/via',
    'keychron/k4/rgb/v1/optical',
    'keychron/k4/rgb/v1/optical_via',
    'keychron/k4/rgb/v2',
    'keychron/k4/rgb/v2/via',
    'keychron/k4/rgb/v2/optical',
    'keychron/k4/rgb/v2/optical_via']

error = False
for kb in BOARDS:
    if subprocess.run(f"qmk compile -kb {kb} -km all -j{os.cpu_count()}", shell=True).returncode != 0:
        error = True
if error:
    sys.exit(1)
