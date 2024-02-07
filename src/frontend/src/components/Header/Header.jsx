import style from './Header.module.css'
import {NavLink} from 'react-router-dom'

const ActiveLink = () => {
  return (
    url => url.isActive ? style.activeItem : style.item
  );
}

const Header = () => {
  return (
      <header className={style.outbox}>
        <div className={style.loginBlock}>
          Petrov D.K. from London
        </div>
        <div className={style.headText}>
          <NavLink to="/" className={ActiveLink()} >-= Study-Test.Online =-</NavLink>
        </div>
      </header>
  );
}

export default Header;
