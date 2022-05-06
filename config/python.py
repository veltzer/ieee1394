import config.project

package_name = config.project.project_name

console_scripts = []
setup_requires = []
run_requires = []
test_requires = []
dev_requires = [
    "pymakehelper",
    "pydmt",
    "pyclassifiers",
]
install_requires = list(setup_requires)
install_requires.extend(run_requires)

extras_require = {}

python_requires = ">=3.9"
test_os = ["ubuntu-20.04"]
test_python = ["3.9"]
