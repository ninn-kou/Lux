## Lab: Using Git 🐯

> This chapter is from Lab 01, COMP1531 20T3, UNSW.

This exercise is intended to help you familiarise yourself with git. If you've not used git before, it can take a while to get used to it and learn how it works. Make sure you understand exactly what you're doing in the following exercise. **DO NOT BLINDLY ENTER IN THE COMMANDS WITHOUT KNOWING WHAT THEY DO.**

### 0. Preparation Work

#### Register an Account on GitHub

[GitHub](https://github.com/)

#### Adding Your SSH Key to GitHub

You need to add your ssh key to your GitHub account. You can follow the below link to finish this task.

<https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh>

### 1. Getting Git

Git is a distributed version control system. It allows you to record changes to a set of files over time and synchronise those changes across many *repositories*. You don't have direct access to that computer, so in order to make changes to files contained within it, you need to copy it to a *local* repository. You can make changes to this local repository then "push" those changes to GitLab. To do that, however, git needs to be installed and configured:

If git is installed on the computer you are using. You can do this by running:

```bash
git status
```

If it is installed you will see something like

```
fatal: Not a git repository (or any of the parent directories):
```

If you do not have git installed, you will see something like

```bash
git: command not recognized
```

If this is the case, you will have to set it up using the following instructions:
  - **Linux** - Follow instructions at <https://git-scm.com/download/linux>
  - **Mac** - Either download from <https://git-scm.com/download/mac> or install via Homebrew or similar.
  - **Windows** - Download from <https://gitforwindows.org/>

There are other means of getting git for all of these platforms. You are free to use whatever means works best for you.

Then, onfigure git if you have not used it before. The following commands will do that.

```bash
git config --global user.name "Your Name"
git config --global user.email "email@example.com"
git config --global push.default simple
git config --global pull.rebase true
```

### 2. Cloning

Cloning a *repository* (a repository or repo is just a directory that is linked with git) copies to your computer all the files in the repo as well as a complete history of what changes, or *commits*, created those files. Cloning a repo is necessary before you can start making your own changes.

To clone a repository with SSH, click on the blue **Clone** button on the top right of this page. Copy the URL under **Clone with SSH**.

```bash
git clone [URL_you_copied]  ## Clone the remote repo to your machine
cd [name_of_repository]     ## To navigate into the directory
```

### 3. Making a Commit

Now that you have cloned the repo, you are ready to work on the codebase locally.

A commit represents a set of changes to the files in a repository as well as a message describing those changes for human readers. A good use of git involves a lot of commits with detailed messages.

Before you can commit, you have to *stage* your changes, effectively telling git what changes you actually want to commit and what changes you don't.

Making commits doesn't actually replicate your changes to the remote repository on GitLab. For that you need to *push* your commits, uploading them to the remote server. When collaborating with others, it is important not only to commit frequently, but also to push often.

In general, the commands to commit and push are as follows:

```bash
git add [files_to_commit]                                 ## Stage
git commit -m "Detailed message describing the changes"   ## Commit
git push                                                  ## Push
```

Follow these steps to see them in action:
1. Create an empty file (in your favourite editor) called `first.txt` and save it in the repo directory
2. Add a line of text to `first.txt`.
3. Once complete, go back to your terminal and enter the following commands:

    ```bash
    git add first.txt
    git commit -m "Added a line to the first file"
    git push
    ```

4. **MAKE SURE YOU UNDERSTAND THE PURPOSE OF EACH OF THE 3 ABOVE COMMANDS!** If you are unsure about any of them, ask your tutor or lab assistant.
5. Go back to GitHub and confirm that your changes have been pushed to the server (you may need to refresh the page).

### 4. Working with Others

Usually when you are using git, it is in a team. That means that you will not be the only one who is making the changes. If someone else makes a change and pushes it to the server, your local repo will not have the most up to date version of the files. Luckily, git makes it easy to update our local copy with the `git pull` command.

This command checks the remote server that your local repo is linked to and makes sure that all of your files are up to date. This ensures that you don't accidentally do things like implement the same thing someone else has already done and also lets you use other people's work (e.g. new functions) when developing.

Pulling regularly is one of the **most important** practices in git!

Unfortunately, at the moment you are just working individually. But GitHub still gives us a nice way to practice a `git pull`.

**Instructions:**

1. View your repo on GitHub.
2. Click on the `.txt` file
3. Click 'Edit' on the right-hand side.
4. Make some small change to the line of text and click the ‘Commit Changes’ button at the bottom of the screen.
5. This will have changed the `first.txt` file on the server but not on your local environment. To fetch these changes use the `git pull` command from your terminal
6. Confirm that your version of `first.txt` now has the changes you made on the web site

### 5. Branching

**Branches** are a vital part of git and allow people to work on separate parts of the codebase and not interfere with one another, or risk breaking a product that is visible to the client. Breaking something on one branch does not have an impact on any other.

Good use of git will involve separating distinct features of the project that can be worked on separately and having them in their own branch. These branches can then be merged when they are ready.

Useful commands for branches:

```bash
git checkout -b [new_branch_name]   ## Create a new branch and switch to it
git branch                          ## List all current branches
git checkout [branch_name]          ## Switch to an existing branch
```

Follow these instructions to create a branch:

1. Make your new branch with: `git checkout -b [new_branch_name]`
2. List your branches to see that you have indeed swapped (use the above commands)
3. Make another change to the `first.txt` file
4. Try to push your changes to the server using the commands you learnt in the _Make your first commit_ section
5. The above step should have given you the following error:

    ```
    fatal: The current branch first_new_branch has no upstream branch.
    ```

    This means that the branch you tried to make a change on doesn't exist on the server yet which makes sense because we only created it on our local machine.
6. To fix this, we need to add a copy of our branch on the server and link them up so git knows that this new branch maps to a corresponding branch on the server. This command will do that:

    ```bash
    git push -u origin [new_branch_name]
    ```

**Note:** The final step only needs to be done for the first time you try to push using a new branch. After you have run this once, you should go back to simply using `git push`.

### 6. Merging

Merging branches is used to combine the work done on two different branches and is where git's magic really comes in. Git will compare the changes done on both branches and decide (based on what changes were done to what sections of the file and when) what to keep. Merges are most often done when a feature branch is complete and ready to be integrated with the master branch.

Since we have finished all that we are going to do (and believe there are no bugs) on our *first_new_branch* we can merge it back into master.

**NOTE**: It is strongly recommended, both in this course and in general, to always ensure the code on the `master` branch works correctly and is free of bugs. This is not always easy to achieve, but you should endeavour to keep master as *stable* as possible.

Another recommendation is to merge *master* into your branch *before* merging *your branch* into master as this will ensure that any merge into master will go smoothly.

In general, merges are done by:

```bash
git merge [target] ## Merge the target branch into the current branch
```

**Note:** A successful merge automatically uses the commits from the source branch. This means that the commits have already been made, you just need to push these to the server (`git push`)

To merge your changes from above:
1. Switch back to the `master` branch using one of the commands from the above section
2. Merge in the changes you made in the other branch

    `git merge first_new_branch`

3. Push the successful merge to the server to update the master branch on the server

### 7. Merge Conflicts

Merge conflicts are the one necessary downside to git. Luckily, they can be avoided most of the time through good use of techniques like branches, regular commits, pushing and pulling. They happen when git cannot work out which particular change to a file you really want.

For this step we will engineer one so you can get a taste of what they are, how they occur and how to fix them. This will be the LAST time you will want one. The process may seem involved but it is quite common when multiple people are working at a time.

Follow these steps:

1. Add a line to the top of the `first.txt` file (on *master branch*)
2. Add, commit and push your changes
3. Switch to your `first_new_branch`
4. Add a different line to the top of the `first.txt` file
5. Add, commit and push your changes
6. Merge master into your current branch
7. This sequence of steps should made a merge conflict at the top of the `first.txt` with the following output
`Auto-merging first.txt`
``CONFLICT (content): Merge conflict in first.txt``
``Automatic merge failed; fix conflicts and then commit the result.``

### 8. Resolving a Merge Conflict

Resolving a merge conflict is as simple as editing the file normally, choosing what you want to have in the places git wasn't sure.

A merge conflict is physically shown in the file in which it occurs.
`<<<<<<<` marks the beginning of the conflicting changes made on the **current** (merged into) branch.
`=======` marks the beginning of the conflicting changes made on the **target** (merged) branch.
`>>>>>>>` marks the end of the conflict zone.

E.g.

```
This line could be merged automatically.
There was no change here either
<<<<<<< current:sample.txt
Merges are too hard. This change was on the 'merged into' branch
=======
Merges are easy. This change was made on the 'merged' branch
>>>>>>> target:sample.txt
This is another line that could be merged automatically
```

This above example could be solved in many ways, one way would be to just use the changes made on the target branch and delete those made on the current branch. Once we have decided on this we just need to remove the syntax. The resolved file would be as follows

```
This line could be merged automatically.
There was no change here either
Merges are easy. This change was made on the 'merged' branch
This is another line that could be merged automatically
```

We would then just commit the resolved file and the merge conflict is finished!

To fix the conflict you created:
1. Open the `first.txt` file and decide which change you want to keep
2. Remove the merge conflict syntax
3. Add, commit and push the resolved merge conflict

### 9. Testing

Checkout `master` and merge `first_new_branch` back into it. You can now run `./test_git.sh` to check whether you have done the git exercises.
