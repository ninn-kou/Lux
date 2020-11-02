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

- `ls`
- `cd`
- `cp`
- `mkdir`
- `ls`
- `ssh`
- `git`
- `rm`
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
