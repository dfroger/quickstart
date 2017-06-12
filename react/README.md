Install nodejs:

    conda create -c conda-forge -n <env_name> nodejs
    source activate <env_names>

Install npm packages:

    npm install --save react react-dom
    npm install --dev webpack babel-loader babel-core babel-preset-es2015 babel-preset-react
    npm install -g webpack

Build application:

    webpack
