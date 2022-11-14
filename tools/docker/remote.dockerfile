FROM development

# Install Node
RUN wget -qO- https://raw.githubusercontent.com/creationix/nvm/v0.31.6/install.sh | bash
RUN export NVM_DIR="$HOME/.nvm"
RUN [ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh"
RUN nvm install 14

# Install code server
RUN npm install -g code-server

ENV PASSWORD="Hello"

# Run code server
CMD ["code-server"]