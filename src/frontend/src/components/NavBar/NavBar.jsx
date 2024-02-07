import style      from './NavBar.module.css'
import {NavLink}  from 'react-router-dom'

const ActiveLink = () => {
  return (
    url => url.isActive ? style.activeItem : style.item
  );
}

const NavBar = () => {

  return (
      <navbar className={style.navbar}>
        <div>
          <NavLink to="/user-section-select" className={ActiveLink()}>User Menu</NavLink>
        </div>
        <div>
          <NavLink to="/admin-test-manage" className={ActiveLink()}>Admin Menu</NavLink>
        </div>
        <div className={style.vSpacer} >
          <NavLink to="/about-us" className={ActiveLink()}>About Us</NavLink>
        </div>
      </navbar>
  );
}

export default NavBar;
