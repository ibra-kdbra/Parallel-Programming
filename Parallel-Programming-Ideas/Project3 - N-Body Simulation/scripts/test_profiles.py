import os

test_repeat_num = 5

max_iteration = 100

build_path = "build-release-nogui/src"
slurm_scripts_path = "slurm_scripts"

n_bodies = [500, 2500, 5000]

def run_test(sbatch_config: str, job_script: str, command: str):    
    with open(f"{slurm_scripts_path}/{job_script}", "w+") as f:
        f.write(sbatch_config)
        f.write("\n")
        for _ in range(test_repeat_num):
            f.write(command)
        
    os.system(f"sbatch {slurm_scripts_path}/{job_script}")