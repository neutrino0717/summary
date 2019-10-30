#!/usr/bin/env eepython
import tarfile
tar = tarfile.open("1419_973_emalavn_BS.tar.gz")
tar.extractall()
tar.close()
tar = tarfile.open("R10A72_standalone_ss7.tar.gz")
tar.extractall()
tar = tarfile.open("R15B01_halfword.tar.gz")
tar.extractall()

import shutil
shutil.move('/root/lab/testtools/rhel664/dallas','/lab/testtools/rhel664/')
shutil.move('/root/lab/testtools/rhel664/otp/R15B01_halfword','/lab/testtools/rhel664/otp/')
shutil.copy2('/root/var/dallas/1419_973_emalavn_BS','/var/dallas/OP305_R10A72')
shutil.copytree('/root/var/dallas/1419_973_emalavn_BS','/var/dallas/OP305_R10A72')
shutil.rmtree(deploy_to_data_dir, ignore_errors=True)
if not os.path.isdir(deploy_to_data_dir):
   shutil.copytree(base_data_dir, deploy_to_data_dir)
os.listdir('/lab/testtools/rhel664')

