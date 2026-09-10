# terminal-rpg agent instructions

Read `CLAUDE.md` for the project's build command, architecture, and coding
conventions. These are repo-specific GitHub and CLI facts.

## GitHub repository

- The repository is `EmpressIrulan/terminal-rpg`, not
  `EmpressIrulanBot/terminal-rpg`.
- It is public. `main` requires one approving review and the `build` status check;
  protection uses `strict: false` and does not enforce admin approval.
- `EmpressIrulan` is the owner and `EmpressIrulanBot` is a write collaborator.
  The bot is not an admin and cannot merge an unapproved change.
- Auto-merge and delete-branch-on-merge are enabled.

Follow the global GitHub identity rule for all writes. When checking the full
repo inventory, query it as `EmpressIrulan`; the bot account only lists repos it
owns or can see as a collaborator. `gh repo list` without an owner lists only
repos owned by the active account.

## CLI quirks

- Use `gh issue view <N> --json number,title,state,body,labels`. Plain
  `gh issue view <N>` hits a deprecated Projects-classic GraphQL field in this
  repository.
