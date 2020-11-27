# Shell Commands

TODO: Re-style this documents.

## Some Useful Commands

### Paths

- `/.`
- `/..`
- `./`
- `../`
- `../../`
- `~/`

### Basic Commands

- `cd`
- `cp`
- `mkdir`
- `ls`
  - `ls -a`
- `ssh`
- `git`
- `rm`
  - `rm -r`
  - `rm -f`
- `mv`

### Remove Specific Files Recursively

```
find . -name "file_name" -exec rm -rf {} \;
```

### Transfer files between server an local PC

```
scp <origin source> <target path>
```

Local PATH: `/Folder(s)/file`
Remote Path: `USER@domain:~/Folder/file`
