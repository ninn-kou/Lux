## Unix-like OS Commands

### Representation of Paths

| PATH                | COMMAND | EXAMPLE                  |
|---------------------|---------|--------------------------|
| Root Directory      | `/`     | `cd /`                   |
| Home Directory      | `~`     | `~/.rcinfo`              |
| Directory Separator | `/`     |                          |
| Current Directory   | `.`     | `./inthisdir`            |
| Parent Directory    | `..`    | `../../greatgrandparent` |

### Basic Shell Commands

- `pwd`: Show the current full path.
- `ls`: List files in the current direction.
- `ls -a`: Show all files, including hiding files which name start as a `.`dot.
- `cd {dir_name}`: Change directory to the target whose name is "dir_name".
- `mkdir {dir_name}`: Make a new directory under current path called "dir_name".
- `rm {file_name}`: Remove or delete the single file called "file_name".
- `rm -r {dir_name}`: Remove the directory and all including files called "dir_name" recursively.
- `mv {old_path} {new_path}`: Move a file from "old_path" to "new_path", or rename it. Actually, they are same.
- `cp {source_file} {target_folder}`: Copy files or directories (use "-R" Parameter to indicate recursively copying) to target path.

### Examples

#### Remove Specific Files Recursively

```
find . -name "{file_name}" -exec rm -rf {} \;
```

#### Connect to a Remote Server

```
ssh {remote_server}
```

#### Transfer Files between Server and Local PC

```
scp {source_file} {target_folder}
```

Local PATH: `/Folder(s)/file`
Remote Path: `USER@domain:~/Folder/file`
