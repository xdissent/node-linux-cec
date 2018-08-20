module.exports = {
  presets: [
    '@babel/preset-flow',
    [
      '@babel/preset-env',
      {
        targets:
          process.env.NODE_ENV === 'test' ? {node: true} : {node: '10.7'},
        modules: process.env.BABEL_ENV === 'es' ? false : 'commonjs'
      }
    ]
  ]
}
