import subprocess
import os
import sys

BOARDS = [
    'keychron/k2/rgb',
    'keychron/k3/rgb',
    'keychron/k4/rgb/v1',
    'keychron/k4/rgb/v2',
    'keychron/k6/rgb',
    'keychron/k6/rgb/via',
    'keychron/k6/white',
    'keychron/k7/rgb',
    'keychron/k7/rgb/optical',
    'keychron/k8/rgb',
    'keychron/k8/rgb/via',
    'keychron/k8/rgb/optical',
    'keychron/k8/rgb/optical_via',
    'keychron/k14/rgb',
    'keychron/k14/rgb/via',
    'akko/3061_rgb']

error = False
for kb in BOARDS:
    if subprocess.run(f"qmk compile -kb {kb} -km all -j{os.cpu_count()}", shell=True).returncode != 0:
        error = True
if error:
    sys.exit(1)
